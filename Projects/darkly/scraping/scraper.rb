require 'rubygems'
require 'nokogiri'
require 'open-uri'

BASE_URL = "http://192.168.82.128/.hidden/".freeze
README = "README".freeze
SPACE = " ".freeze

OPEN_URL = -> (url) { Nokogiri::HTML(open(url)) }

def depth_search(url_prefix)
	urls = OPEN_URL.call(url_prefix).css('a')[1..-1].map { |link| url_prefix + link }
	urls.each do |url|
		puts url
		if (url.include? README)
			content = OPEN_URL.call(url).text
			puts content if (!content.include? SPACE)
			return
		end
		depth_search(url)
	end
end

depth_search(BASE_URL)
